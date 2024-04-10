//package TaskB

fun fetch(): String
{
	return readLine()!!
}

fun main()
{
	var cnt = arrayOf<Array<Int>>()
	val ALPHABET = 26
	val MIN_LETTER = 'A'.toByte().toInt()
	
	for (i in 0 .. ALPHABET - 1)
	{
		var row = arrayOf<Int>();
		
		for (j in 0 .. ALPHABET - 1)
			row += 0;
		
		cnt += row
	}
	
	val n = fetch().toInt()
	val string = fetch()
	
	for (i in 0 .. n - 2)
	{
		val fst = string[i].toByte().toInt() - MIN_LETTER
		val snd = string[i + 1].toByte().toInt() - MIN_LETTER
		
		++cnt[fst][snd];
	}
	
	var answ = "XX";
	var max_cnt = -1
	
	for (i in 0 .. ALPHABET - 1)
	{
		for (j in 0 .. ALPHABET - 1)
		{
			if(cnt[i][j] > max_cnt)
			{
				var new_answ = ""
				
				new_answ += (i + MIN_LETTER).toChar()
				new_answ += (j + MIN_LETTER).toChar()
				
				answ = new_answ
				max_cnt = cnt[i][j]
			}
		}	
	}
	
	println(answ)
}