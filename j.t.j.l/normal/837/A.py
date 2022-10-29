n = raw_input()
s = raw_input().split(" ")
ans = 0
for x in s:
	cnt = 0
	for y in x:
		if (y.isupper()):
			cnt += 1
	ans = max(ans, cnt)
print(ans)