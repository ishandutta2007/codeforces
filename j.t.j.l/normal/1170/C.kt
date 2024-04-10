import java.io.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun printInts(a: Array<Int>) = println(a.joinToString("\n")) 
private fun bufferOut(block: PrintWriter.() -> Unit) = PrintWriter(System.out).use { block(it) }

fun main(args: Array<String>) = bufferOut { readSolveWrite() }

private fun PrintWriter.readSolveWrite() {
    val tt = readLine()!!.toInt()
    repeat(tt) {
        val s = readLn()
        val t = readLn()
        val n = s.length
        val m = t.length
        val idx = IntArray(3)
        idx[0] = 0
        idx[1] = 0
        idx[2] = 1
        while (idx[0] < n && idx[1] < m) {
            if (s[idx[0]] == t[idx[1]]) {
                idx[0] += 1
                idx[1] += 1
            }
            else {
                if (s[idx[0]] == '+') {
                    idx[2] = 0
                    break
                }
                else {
                    if (idx[0] + 1 < n && s[idx[0] + 1] == '-') {
                        idx[0] += 2
                        idx[1] += 1
                    }
                    else {
                        idx[2] = 0
                        break
                    }
                }
            }
        }
        if (idx[0] != n || idx[1] != m) {
            idx[2] = 0
        }
        if (idx[2] == 0) {
            println("NO");
        }
        else {
            println("YES");
        }
        // val n = readLine()!!.toInt()
        // val es = ArrayList<Evt>(2 * n)
        // repeat(n) { i ->
        //     val (l, r) = readLine()!!.split(" ").map { it.toInt() }
        //     es += Evt(i, l, 1)
        //     es += Evt(i, r, -1)
        // }
        // val r = solveEvents(n, es)
        // if (r == null) {
        //     println(-1)
        // } else {
        //     println(r.joinToString(" "))
        // }
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