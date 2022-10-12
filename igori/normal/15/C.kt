import javax.swing.text.Segment
import kotlin.math.*

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }

fun comp(a: Long) = when ((a % 4).toInt()) {
    3 -> 0
    0 -> a
    1 -> 1
    2 -> a + 1
    else -> 0
}

fun main()
{
    val n = readInt()
    var x = 0L
    repeat(n) {
        val (a, m) = readLine()!!.split(' ').map { it.toLong() }
        x = x xor comp(a - 1)
        x = x xor comp(a + m - 1)
    }
    if (x == 0L) {
        println("bolik")
    } else {
        println("tolik")
    }
}