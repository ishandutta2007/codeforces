fun main() {
    val t = readLine()!!.toInt()
    for(x in 1..t) {
        val l = readLine()!!.split(" ").map{it.toInt()}
        println(l[0] + l[1])
    }
}