import kotlin.math.abs

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m, y, x) = readLine()!!.split(" ").map { it.toLong() }
        val s = Pair(y, x)
        val corners = listOf(Pair(1L, 1L), Pair(1L, m), Pair(n, 1L), Pair(n, m))
        fun dist(p: Pair<Long, Long>, q: Pair<Long, Long>): Long {
            val (y1, x1) = p
            val (y2, x2) = q
            return abs(y2 - y1) + abs(x2 - x1)
        }
        var maxDist = -1L
        var answer = ""
        for (p in corners) {
            for (q in corners) {
                val d = dist(s, p) + dist(p, q) + dist(q, s)
                if (d > maxDist) {
                    answer = "${p.first} ${p.second} ${q.first} ${q.second}"
                    maxDist = d
                }
            }
        }
        println(answer)
    }
}