import java.io.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun printInts(a: IntArray) = println(a.joinToString("\n")) 
private fun bufferOut(block: PrintWriter.() -> Unit) = PrintWriter(System.out).use { block(it) }

fun main(args: Array<String>) = bufferOut { readSolveWrite() }

private fun PrintWriter.readSolveWrite() {
    val t = readLine()!!.toInt()
    // val ans = IntArray(t)
    for (i in 1..t) {
        val n = readLine()!!.toInt()
        var l = (n - 1) / 7 + 1
        var r = n / 2
        // ans[i - 1] = r
        println(r)
    }
    //printInts(ans)
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