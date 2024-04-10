import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val a = jin.readLine().split(" ").map { it.toLong() }.toMutableList()
        val b = jin.readLine().split(" ").map { it.toLong() }.toMutableList()
        var z = min(a[2], b[1])
        var answer = 2L * z
        a[2] -= z
        b[1] -= z
        a[1] -= min(a[1], b[0] + b[1])
        b[2] -= min(b[2], a[0] + a[2])
        answer -= 2L * min(a[1], b[2])
        out.appendln(answer)
    }
    print(out)
}