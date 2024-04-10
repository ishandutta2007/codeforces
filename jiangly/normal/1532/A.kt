fun main() {
    var t = readLine()!!.toInt()
    for (i in 1..t) {
        var ab = readLine()!!.split(' ').map { it.toInt() }
        println(ab[0] + ab[1])
    }
}