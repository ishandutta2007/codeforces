import java.io.File
import java.io.PrintWriter
import kotlin.math.min


val pw = PrintWriter(System.out)
fun main() {
    val (n, bytes) = listOfInt()
    val bits = bytes * 8


    val kind = 1 shl (min(30, bits / n))
    val ar = listOfInt().sorted()
    val occur =mutableListOf<Int>()
    var i = 0
    while (i < n) {
        var j = i
        while (j < n && ar[j] == ar[i]) {
            ++j
        }
        occur += j - i
        i = j
    }
//    val occur = ar.groupingBy {it}.eachCount().toSortedMap().values.toIntArray()
    val m = occur.size
    val accum = IntArray(m + 1)
    repeat(m) { i ->
        accum[i+1] = accum[i] + occur[i]
    }

    var res = n
    repeat(m) { i ->
        res = min(res, accum[i] + if (i + kind <= m) accum[m] - accum[i+kind] else 0)
    }

    pw.println(res)
    pw.flush()
}

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun listOfString() = next().split(" ")
fun listOfInt() = listOfString().map { it.toInt() }
fun listOfLong() = listOfString().map { it.toLong() }
fun listOfDouble() = listOfString().map { it.toDouble() }