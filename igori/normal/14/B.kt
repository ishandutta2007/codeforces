import kotlin.math.*

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }

fun main()
{
    val (n, x0) = readInts()
    var (maxL, minR) = Pair(0, 1000)
    repeat(n) {
        var (l, r) = readInts()
        if (l > r) {
            l = r.also { r = l }
        }
        maxL = max(maxL, l)
        minR = min(minR, r)
    }
    if (maxL > minR) {
        println(-1)
    } else {
        if (x0 in (maxL + 1) until minR) {
            println(0)
        } else {
            println(min(abs(x0 - maxL), abs(x0 - minR)))
        }
    }
}