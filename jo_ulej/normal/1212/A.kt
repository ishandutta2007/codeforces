fun fetch(): String
{
	return readLine()!!
}

fun main()
{
	var input = fetch().split(' ')
	var number = input[0].toInt()
	var steps = input[1].toInt()
	
	for (step in 1 .. steps)
		number = if (number % 10 == 0) number / 10 else number - 1
	
	println(number)
}