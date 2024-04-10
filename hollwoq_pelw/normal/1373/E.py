for _ in range(int(input())):
	N, K = map(int, input().split());
	ans = float("inf")
	
	for i in range(100 - K):
		val = 0
		for j in range(i, i + K + 1):
		    val += sum(list(map(int, list(str(j)))))
		if (N - val) % (K + 1) == 0 and N >= val:
		    x = int((N - val) // (K + 1));
		    tail = str(x % 9) + str("9") * int(x // 9);
		    if (i < 10):
		        ans = min(ans, int(tail+"0"+str(i)))
		    else:
		        ans = min(ans, int(tail+str(i)))

	print(-1) if ans == float("inf") else print(ans)