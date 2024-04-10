s = input()
n = int(s,2)
k = 1
ans = 0
while n > k:
	k <<= 2
	ans += 1
print(ans)