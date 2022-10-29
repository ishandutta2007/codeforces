import java.io.*
import java.util.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun printInts(a: Array<Int>) = println(a.joinToString("\n")) 
private fun bufferOut(block: PrintWriter.() -> Unit) = PrintWriter(System.out).use { block(it) }

fun main(args: Array<String>) = bufferOut { readSolveWrite() }

private fun PrintWriter.readSolveWrite() {
    val (n, m, k) = readInts()
    val aa = readInts()
    val a = IntArray(n)
    for (i in 0..(n - 1)) {
        a[i] = aa[i]
    }
    val random = Random(19260817L)
    for (i in 1..(n - 1)) {
        val j = random.nextInt(i)
        val t = a[i]
        a[i] = a[j]
        a[j] = t
    }
    a.sort()
    // for (x in a) {
    //     print(x)
    //     print(" ")
    // }
    // println("")
    val sm = LongArray(n + 1)
    for (i in 1..n) {
        sm[i] = sm[i - 1] + a[i - 1]
    }
    val ONE: Long = 1
    val ed = n - m;
    var lm = 0
    var ans: Long = 1000000000;
    ans = ans * ans;
    for (st in 0..ed) {
        val mid = (st + (m - 1) / 2)
        // println(">>>");
        while (lm + 1 < n && (ONE * a[lm + 1] * (lm + 1 - st + 1) - (sm[lm + 2] - sm[st]) <= k)) {
            lm += 1
        }
        var u: Long = 0
        if (lm >= mid) {
            val aim: Long = a[mid] + ONE - ONE
            val leq = mid - st + 1
            val gth = st + m - 1 - mid
            val res: Long = (sm[st + m] - sm[mid + 1]) - aim * gth + aim * leq - (sm[mid + 1] - sm[st]);
            if (res < ans) {
                ans = res;
            }
            u = res
        }
        else {
            val leq = lm - st + 1
            val gth = st + m - 1 - lm
            val rmi = (k - (ONE * a[lm] * leq - (sm[lm + 1] - sm[st]))) / leq
            val aim: Long = a[lm] + rmi + ONE - ONE
            val res: Long = (sm[st + m] - sm[lm + 1]) - aim * gth + aim * leq - (sm[lm + 1] - sm[st]);
            if (res < ans) {
                ans = res;
            }
            u = res
        }
        // print(st)
        // print(" ")
        // print(mid)
        // print(" ")
        // print(lm)
        // print(" ")
        // println(u)
//        println("???");
    }
    println(ans)
}

class Evt(val i: Int, val p: Int, val d: Int)

private fun solveEvents(n: Int, es: ArrayList<Evt>): IntArray? {
    es.sortWith(Comparator { e1, e2 ->
        when {
            e1.p < e2.p -> -1
            e1.p > e2.p -> 1
            else -> e2.d - e1.d
        }
    })
    var cnt = 0
    val r = IntArray(n)
    var cur = 1
    var cc = 0
    for (e in es) {
        cnt += e.d
        when {
            e.d == 1 -> {
                r[e.i] = cur
                cc++
            }
            cnt == 0 && cur == 1 -> {
                cur = 2
                cc = 0
            }
        }
    }
    return if (cc == 0) null else r
}