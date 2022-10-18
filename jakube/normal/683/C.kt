fun main(args: Array<String>) {
    val map: MutableList<Pair<Int, String>> = mutableListOf()

    val l1 = (readLine() as String).split(' ').map { it.toInt() }
    val l2 = (readLine() as String).split(' ').map { it.toInt() }

    val s1 : MutableSet<Int> = mutableSetOf()
    val s2 : MutableSet<Int> = mutableSetOf()
    val s3 : MutableSet<Int> = mutableSetOf()
    val s4 : MutableSet<Int> = mutableSetOf()


    for (i in 1..l1[0])
    {
        s1.add(l1[i])
        s3.add(l1[i])
    }

    for (i in 1..l2[0])
    {
        s2.add(l2[i])
        s4.add(l2[i])
    }


    val result = s3.minus(s2).plus(s4.minus(s1))

    print(result.size)
    val t = result.toList().sortedBy { it }

    for (i in t) {
        print(' ')
        print(i)
    }


}