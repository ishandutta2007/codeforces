import java.util.StringTokenizer
import java.io.InputStreamReader
import java.io.BufferedReader
import java.io.InputStream

fun fetch(): String
{
	return readLine()!!
}

fun main()
{
	R.init(System.`in`)
	
	val n = R.nextInt().toLong()
	var k = R.nextInt().toLong()
	
	var data = mutableListOf<Pair<Long, Long>>()
	var answ: Long = 0
	
	for(i in 0 .. n - 1)
	{
		val a = R.nextInt().toLong()
		val b = R.nextInt().toLong()
		val c = R.nextInt().toLong()
		
		k -= a
		answ += a * c
		data.add(Pair(c, b - a))
	}
	
	if(k < 0)
	{
		println("-1")
	}
	else
	{
		data.shuffle()
		data.sortWith(compareBy({it.first}, {it.second}))
		
		for(pr in data)
		{
			var take = pr.second
			
			if(take > k)
			{
				take = k
			}
			
			answ += take * pr.first
			k -= take
		}
		
		if(k == 0.toLong())
	    {
		    println(answ)
		}
		else
		{
		    println("-1")
		}
	}
}

// copied from H0ssein url: https://codeforces.com/contest/1171/submission/54696549

internal object R {
    private lateinit var reader: BufferedReader
    private lateinit var tokenizer: StringTokenizer
    fun init(input: InputStream) {
        reader = BufferedReader(InputStreamReader(input))
        tokenizer = StringTokenizer("")
    }
 
    fun next(): String {
        while (!tokenizer.hasMoreTokens()) tokenizer = StringTokenizer(reader.readLine())
        return tokenizer.nextToken()
    }
 
    fun nextInt() = next().toInt()
    fun nextDouble() = next().toDouble()
}