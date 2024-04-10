n = int(input())
a = list(map(int,input().split()))
ans = 0
zero = posi = nega = 0
for i in a:
	if i == 0:
		zero += 1
	elif i > 0:
		posi += 1
		ans += i-1
	else:
		nega += 1
		ans += -1-i
if nega&1 and not zero:
	ans += 2
ans += zero
print(ans)