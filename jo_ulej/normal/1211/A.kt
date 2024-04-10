//package TaskA

fun fetch(): String
{
	return readLine()!!
}

fun main()
{
	val n = fetch().toInt()
	val arr: Array<Int> = fetch().split(' ').map({x -> x.toInt()}).toTypedArray()
	
	var found = false
	
	for(i in 0 .. n - 1)
	{
		var left = -1
		var right = -1
		
		for(j in 0 .. n - 1)
		{
			if(arr[j] < arr[i])
				left = j
		}
		
		for(j in 0 .. n - 1)
		{
			if(arr[j] > arr[i] && j != left)
				right = j
		}
		
		if(left != -1 && right != -1)
		{
			print(left + 1)
			print(' ')
			print(i + 1)
			print(' ')
			println(right + 1)
			
			found = true
			break
		}
	}
	
	if(!found)
	{
		println("-1 -1 -1")
	}
}