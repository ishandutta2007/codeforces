import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val ay = jin.readLine().split(" ").map { it.toLong() }
    val by = jin.readLine().split(" ").map { it.toLong() }
    var g = 0L
    for (j in 1 until n) {
        g = gcd(g, abs(ay[j] - ay[0]))
    }
    println(by.map { gcd(g, it + ay[0]) }.joinToString(" "))
}

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)