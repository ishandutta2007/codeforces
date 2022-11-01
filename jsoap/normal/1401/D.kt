import java.io.BufferedInputStream
import kotlin.math.max

const val MOD = 1000000007L

fun main() {
    val jin = FastScanner()
    val out = StringBuilder()
    for (c in 1..jin.nextInt()) {
        val n = jin.nextInt()
        val adj = Array(n + 1) { mutableListOf<Int>() }
        for (j in 2..n) {
            val a = jin.nextInt()
            val b = jin.nextInt()
            adj[a].add(b)
            adj[b].add(a)
        }
        val seen = BooleanArray(n + 1)
        val edges = mutableListOf<Long>()
        fun recur(a: Int): Int {
            return if (seen[a]) {
                0
            } else {
                seen[a] = true
                var res = 1
                for (b in adj[a]) {
                    val under = recur(b)
                    if (under != 0) {
                        edges.add(under.toLong() * (n - under).toLong())
                        res += under
                    }
                }
                res
            }
        }
        recur(1)
        edges.sort()
        val m = jin.nextInt()
        val primes = Array(max(n - 1, m)) { if (it < m) jin.nextInt().toLong() else 1L }
        primes.sort()
        for (j in m - 2 downTo n - 2) {
            primes[j] *= primes[j + 1]
            primes[j] %= MOD
        }
        var answer = 0L
        for (j in 0 until n - 1) {
            answer += edges[j] * primes[j]
            answer %= MOD
        }
        out.appendln(answer)
    }
    print(out)
}

class FastScanner {
    private val BS = 1 shl 16
    private val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC
    private var `in`: BufferedInputStream? = null

    constructor() {
        `in` = BufferedInputStream(System.`in`, BS)
    }

    private val char: Char
        private get() {
            while (bId == size) {
                size = try {
                    `in`!!.read(buf)
                } catch (e: Exception) {
                    return NC
                }
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toChar()
        }

    fun nextInt(): Int {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0
        while (c >= '0' && c <= '9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
}