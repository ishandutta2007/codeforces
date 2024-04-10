import java.io.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun printInts(a: Array<Int>) = println(a.joinToString("\n")) 
private fun bufferOut(block: PrintWriter.() -> Unit) = PrintWriter(System.out).use { block(it) }

fun main(args: Array<String>) = bufferOut { readSolveWrite() }

private fun PrintWriter.readSolveWrite() {
    val t = readLine()!!.toInt()
    repeat(t) {
        var s = readLn()
        val vis = IntArray(26)
        for (x in s) {
            vis[x - 'a'] += 1
        }
        var flag = 0
        for (i in 0..25) {
            if (vis[i] > 0) {
                flag = flag + 1
            }
        }
        if (flag == 1) {
            println("-1")
        }
        else {
            var t = StringBuilder()
            for (i in 0..25) {
                for (j in 1..vis[i]) {
                    t.append('a' + i)
                }
            }
            println(t)
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