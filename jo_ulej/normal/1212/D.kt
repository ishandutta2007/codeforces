fun fetch(): String
{
	return readLine()!!
}

fun cnt(x: Long, y: Long): Long
{
	var answ: Long = 0
	var temp: Long = x
	
	while(temp % y == 0L)
	{
		++answ
		temp /= y
	}
	
	return answ
}

fun lt(lhs: Long, rhs: Long): Boolean
{
	return cnt(lhs, 2) - cnt(lhs, 3) < cnt(rhs, 2) - cnt(rhs, 3);
}

fun main()
{
	val n = fetch().toInt()
	var arr: Array<Long> = fetch().split(' ').map { x -> x.toLong()}.toTypedArray()
	
	/*for(i in 0 .. n - 1)
	{
		for(j in 0 .. i)
		{
			if(lt(arr[i], arr[j]))
			{
				var t = arr[i]
				arr[i] = arr[j]
				arr[j] = t
			}
		}
	}*/
	
	arr.sortWith(Comparator<Long> { lhs, rhs ->
		when {
			lt(lhs, rhs) -> -1
			lt(rhs, lhs) -> 1
			else -> 0
		}
	})
	
	for (x in arr)
	{
		print("$x ")
	}
	
	println()
}