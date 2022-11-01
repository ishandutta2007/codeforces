import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, x, y) = jin.readLine().split(" ").map { it.toInt() }
        var answer = listOf(Int.MAX_VALUE)
        for (d in 1..50) {
            if ((y - x) % d == 0 && (y - x) / d < n) {
                val pos = LinkedList<Int>()
                pos.add(y)
                while (pos.size < n && pos.first > d) {
                    pos.addFirst(pos.first - d)
                }
                while (pos.size < n) {
                    pos.addLast(pos.last + d)
                }
                if (pos.last < answer.last()) {
                    answer = pos
                }
            }
        }
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}