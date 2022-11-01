import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    var answer = 1L
    val horizontal = Array(n) {
        val (w, from, to) = jin.readLine().split(" ").map { it.toInt() }
        if (from == 0 && to == 1000000) {
            answer++
        }
        Segment(from, to, w)
    }
    val vertical = Array(m) {
        val (w, from, to) = jin.readLine().split(" ").map { it.toInt() }
        if (from == 0 && to == 1000000) {
            answer++
        }
        Segment(from, to, w)
    }
    val updates = Array(2 * n) { Update(it % 2 == 0, horizontal[it / 2]) }
    updates.sortBy { it.w }
    vertical.sortBy { it.w }
    val bit = BinaryIndexTree(1, 1000000)
    var j = 0
    for (segment in vertical) {
        while (j < 2 * n && updates[j].w <= segment.w) {
            if (updates[j].add) {
                bit.update(updates[j].segment.w, 1L)
            } else {
                bit.update(updates[j].segment.w, -1L)
            }
            j++
        }
        answer += bit[segment.from, segment.to]
    }
    println(answer)
}

data class Segment(val from: Int, val to: Int, val w: Int)
data class Update(val add: Boolean, val segment: Segment) {
    val w = if (this.add) this.segment.from else (this.segment.to + 1)
}

class BinaryIndexTree(val treeFrom: Int, treeTo: Int) {
    val value = LongArray(treeTo - treeFrom + 2)

    fun update(index: Int, delta: Long) {
        var i = index + 1 - treeFrom
        while (i < value.size) {
            value[i] += delta
            i += i and -i
        }
    }

    fun query(to: Int): Long {
        var res = 0L
        var i = to + 1 - treeFrom
        while (i > 0) {
            res += value[i]
            i -= i and -i
        }
        return res
    }

    operator fun get(from: Int, to: Int) = if (to < from) 0L else query(to) - query(from - 1)
}