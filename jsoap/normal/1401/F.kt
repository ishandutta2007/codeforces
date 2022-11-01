import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, q) = jin.readLine().split(" ").map { it.toInt() }
    val segTree = LolSegmentTree(n)
    val tokenizer = StringTokenizer(jin.readLine())
    for (j in 1..(1 shl n)) {
        segTree.update(j, tokenizer.nextToken().toLong())
    }
    val out = StringBuilder()
    for (j in 1..q) {
        val line = jin.readLine().split(" ").map { it.toInt() }
        when (line[0]) {
            1 -> segTree.update(line[1], line[2].toLong())
            2 -> segTree.reverse(line[1])
            3 -> segTree.swap(line[1])
            4 -> out.appendln(segTree.query(line[1], line[2]))
        }
    }
    print(out)
}

class LolSegmentTree(val n: Int) {
    val value = LongArray(1 shl (n + 1))
    val swapped = BooleanArray(n)

    fun query(from: Int, to: Int) = query(from, to, 1, 1, 1 shl n, n - 1)

    fun query(from: Int, to: Int, node: Int, segFrom: Int, segTo: Int, e: Int): Long {
        if (segTo < from || to < segFrom) {
            return 0L
        } else if (from <= segFrom && segTo <= to) {
            return value[node]
        } else {
            val mid = (segFrom + segTo) / 2
            val (left, right) = if (swapped[e]) Pair((2 * node) + 1, 2 * node) else Pair(2 * node, (2 * node) + 1)
            return query(from, to, left, segFrom, mid, e - 1) + query(from, to, right, mid + 1, segTo, e - 1)
        }
    }

    fun update(ix: Int, new: Long) = update(ix, new, 1, 1, 1 shl n, n - 1)

    fun update(ix: Int, new: Long, node: Int, segFrom: Int, segTo: Int, e: Int): Long {
        if (segFrom == segTo) {
            val delta = new - value[node]
            value[node] = new
            return delta
        } else {
            val mid = (segFrom + segTo) / 2
            val delta = if (ix <= mid) {
                update(ix, new, if (swapped[e]) ((2 * node) + 1) else (2 * node), segFrom, mid, e - 1)
            } else {
                update(ix, new, if (swapped[e]) (2 * node) else ((2 * node) + 1), mid + 1, segTo, e - 1)
            }
            value[node] += delta
            return delta
        }
    }

    fun swap(e: Int) {
        swapped[e] = !swapped[e]
    }

    fun reverse(e: Int) {
        for (f in e - 1 downTo 0) {
            swap(f)
        }
    }
}

/*

     1
   2   3
  4 5 6 7

 */