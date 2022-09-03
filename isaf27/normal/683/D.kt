fun main(args: Array<String>) {
    val (q) = readLine()!!.split(' ').map(String::toInt)
    for (i in 1..q)
    {
        var ans = true
        val (n, m, p) = readLine()!!.split(' ').map(String::toInt)
        for (d in 1..p)
            if (p % d == 0 && ans)
            {
                val r = p / d
                if (d <= n && r <= m)
                    ans = false
            }
        if (ans)
            println("No")
        else
            println("Yes")
    }
}