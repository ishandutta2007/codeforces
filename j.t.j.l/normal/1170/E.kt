import java.io.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun printInts(a: Array<Int>) = println(a.joinToString("\n")) 
private fun bufferOut(block: PrintWriter.() -> Unit) = PrintWriter(System.out).use { block(it) }

fun main(args: Array<String>) = bufferOut { readSolveWrite() }

private fun PrintWriter.readSolveWrite() {
    val (n, m) = readInts()
    val a = readInts()
    val sm = IntArray(n + 2)
    for (i in 1..n) {
        sm[i] = sm[i - 1] + a[i - 1]
    }
    sm[n + 1] = sm[n]
    val q = readInt()
    repeat(q) {
        val b = readInts()
        var now = 0
        var door = 0
//        println("================")
//        println(b.joinToString(" "))
        for (i in 1..b[0]) {
            val rng = b[i] - now - 1
            var left = door
            var right = n + 1
            while (left + 1 < right) {
//                print(left)
//                print(" ")
//                print(right)
                val mid = (left + right) / 2
                if (sm[mid] - sm[door] <= rng)
                    left = mid;
                else
                    right = mid;
            }
//            println(rng)
//            println(left)
//            println(door)
//            println(sm[left] - sm[door])
            door = left;
            now = b[i]
        }
        val rng = m + 1 - now - 1;
        var left = door
        var right = n + 1
        while (left + 1 < right) {
//                print(left)
//                print(" ")
//                print(right)
            val mid = (left + right) / 2
            if (sm[mid] - sm[door] <= rng)
                left = mid;
            else
                right = mid;
        }
        door = left;
        if (door >= n) {
            println("YES");
        }
        else {
            println("NO");
        }
    }
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