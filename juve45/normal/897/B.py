k, p = input().split()
p = int(p)
ans = 0
for i in range(1, int(k) + 1):
	nr = str(i) + str(i)[::-1]
	ans += int(nr)
	#print(ans)
	ans %= p
print(ans)