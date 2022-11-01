//package TaskB

fun fetch(): String
{
	return readLine()!!
}

fun main()
{
	val n = fetch().toInt()
	var arr: Array<Int> = fetch().split(' ').map({x -> x.toInt()}).toTypedArray()
	
	var mx = 0
	var last = 0
	
	for(i in 0 .. n - 1)
	{
		var x = arr[i]
		
		if(x > mx)
			mx = x
		
		if(x == mx)
			last = i + 1
	}
	
	var answ: Long = (mx - 1).toLong() * n.toLong() + last.toLong()
	
	println(answ)
}