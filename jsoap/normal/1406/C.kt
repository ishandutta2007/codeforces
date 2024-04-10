import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val adj = Array(n + 1) { mutableListOf<Int>() }
        for (j in 2..n) {
            val (a, b) = jin.readLine().split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        val subtree = IntArray(n + 1) { 1 }
        val seen = BooleanArray(n + 1)
        var best = n
        var centroid1 = 0
        var centroid2 = 0
        fun recur(a: Int) {
            var maxRem = 0
            for (b in adj[a]) {
                if (!seen[b]) {
                    seen[b] = true
                    recur(b)
                    subtree[a] += subtree[b]
                    maxRem = max(maxRem, subtree[b])
                }
            }
            maxRem = max(maxRem, n - subtree[a])
            if (maxRem < best) {
                best = maxRem
                centroid1 = a
                centroid2 = 0
            } else if (maxRem == best) {
                centroid2 = a
            }
        }
        seen[1] = true
        recur(1)
        if (centroid2 == 0) {
            out.appendln("1 ${adj[1][0]}")
            out.appendln("1 ${adj[1][0]}")
        } else {
            var leaf = 1
            while (adj[leaf].size > 1) {
                leaf++
            }
            val dist = IntArray(n + 1) { -1 }
            val stack = Stack<Int>()
            dist[leaf] = 0
            stack.push(leaf)
            while (stack.isNotEmpty()) {
                val a = stack.pop()
                for (b in adj[a]) {
                    if (dist[b] == -1) {
                        dist[b] = dist[a] + 1
                        stack.push(b)
                    }
                }
            }
            out.appendln("$leaf ${adj[leaf][0]}")
            if (dist[centroid1] < dist[centroid2]) {
                out.appendln("$leaf $centroid2")
            } else {
                out.appendln("$leaf $centroid1")
            }
        }
    }
    print(out)
}