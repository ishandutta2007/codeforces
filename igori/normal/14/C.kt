import javax.swing.text.Segment
import kotlin.math.*

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }

typealias segment = Pair<Pair<Int, Int>, Pair<Int, Int>>

fun readSegment() : segment {
    val a = readInts()
    return Pair(Pair(a[0], a[1]), Pair(a[2], a[3]))
}

fun Boolean.toInt() = when(this) {
    true -> 1
    else -> 0
}

fun findSegment(a : MutableList<segment>, s : segment) = a.any { it == s }.toInt()

fun main()
{
    val a = mutableListOf<segment>()
    repeat(4) {
        a.add(readSegment())
    }
    val inf = 1000000000
    var minX = inf
    var maxX = -inf
    var minY = inf
    var maxY = -inf
    a.forEach {
        minX = min(minX, min(it.first.first, it.second.first))
        maxX = max(maxX, max(it.first.first, it.second.first))
        minY = min(minY, min(it.first.second, it.second.second))
        maxY = max(maxY, max(it.first.second, it.second.second))
    }
    var cnt = 0
    cnt += findSegment(a, segment(Pair(minX, minY), Pair(maxX, minY)))
    cnt += findSegment(a, segment(Pair(maxX, minY), Pair(minX, minY)))
    if (cnt != 1) {
        println("NO")
        return
    }
    cnt += findSegment(a, segment(Pair(minX, maxY), Pair(maxX, maxY)))
    cnt += findSegment(a, segment(Pair(maxX, maxY), Pair(minX, maxY)))
    if (cnt != 2) {
        println("NO")
        return
    }

    cnt += findSegment(a, segment(Pair(minX, minY), Pair(minX, maxY)))
    cnt += findSegment(a, segment(Pair(minX, maxY), Pair(minX, minY)))
    if (cnt != 3) {
        println("NO")
        return
    }
    cnt += findSegment(a, segment(Pair(maxX, minY), Pair(maxX, maxY)))
    cnt += findSegment(a, segment(Pair(maxX, maxY), Pair(maxX, minY)))
    if (cnt != 4) {
        println("NO")
        return
    }

    println("YES")
}