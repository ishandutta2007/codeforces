import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    repeat(jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val tokenizer1 = StringTokenizer(jin.readLine())
        val tokenizer2 = StringTokenizer(jin.readLine())
        val xs = LongArray(n + 1) { if (it == 0) 0L else tokenizer1.nextToken().toLong() - tokenizer2.nextToken().toLong() }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        repeat(m) {
            val (a, b) = jin.readLine().split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        var answer = "YES"
        val seen = LongArray(n + 1)
        for (r in 1..n) {
            if (seen[r] == 0L) {
                var here = 0L
                var bipartite = true
                fun dfs(a: Int, sign: Long) {
                    if (seen[a] == 0L) {
                        seen[a] = sign
                        here += sign * xs[a]
                        for (b in adj[a]) {
                            dfs(b, -sign)
                        }
                    } else if (sign != seen[a]) {
                        bipartite = false
                    }
                }
                dfs(r, 1L)
                if (here % 2L != 0L || (bipartite && here != 0L)) {
                    answer = "NO"
                }
            }
        }
        out.appendln(answer)
    }
    print(out)
}