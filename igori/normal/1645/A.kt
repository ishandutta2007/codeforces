fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val a: MutableList<Int> = readInts().toMutableList()
        a.addAll(a)
        a.addAll(a)
        a.forEachIndexed { index, i ->
            if (index != 0 && a[index - 1] != i && a[index + 1] != i) {
                println(index % n + 1)
                return@repeat
            }
        }
    }
}