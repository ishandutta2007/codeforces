fun main(args: Array<String>) {
    val map: MutableList<Pair<Int, String>> = mutableListOf()

    val N = (readLine() as String).toInt()

    for (i in 1..N) {
        val s = (readLine() as String).split(' ')
        val p: Pair<Int, String> = Pair(s[1].toInt(), s[0])
        map.add(p)
    }


    for (o in map.sortedBy { it.first })
        println(o.second)


}