def li():
  return list(map(int, input().split(" ")))
input()
ans = lo = 0
for i in li():
	k = min(lo, i//2)
	i -= 2*k
	lo -= k
	ans += k
	ans += i//3
	lo += (i%3)
print(ans)