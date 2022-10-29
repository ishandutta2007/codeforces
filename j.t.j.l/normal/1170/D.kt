import java.io.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun printInts(a: Array<Int>) = println(a.joinToString("\n")) 
private fun bufferOut(block: PrintWriter.() -> Unit) = PrintWriter(System.out).use { block(it) }

fun main(args: Array<String>) = bufferOut { readSolveWrite() }

private fun PrintWriter.readSolveWrite() {
    val m = readInt()
    val b = readInts()
    val f = IntArray(5)
    f[0] = 0
    for (x in b) {
        if (x == -1) {
            f[0] += 1
        }
    }
    val n = f[0]
    val a = Array<nico>(n, {i -> nico(ArrayList<Int>())})
    val c = IntArray(n)
    for (i in 0..(n - 1)) {
        c[i] = (i + 1) % n
    }
    f[1] = 0
    f[2] = n - 1
    for (x in b) {
        if (x != -1)
            a[f[1]].data.add(x)
        f[1] = c[f[1]]
        if (x == -1) {
            c[f[2]] = f[1]
        }
        else {
            f[2] = c[f[2]]
        }
    }
    println(n)
    for (aa in a) {
        print(aa.data.size)
        print(" ")
        println(aa.data.joinToString(" "))
    }
}

class nico(val data: ArrayList<Int>)
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