import math
n, H = map(int, input().split())
cn = n;

def f(top, H):
	k = (top - H + 1)
	off = 0
	if k % 2 == 1:
		off = k // 2
	k = k // 2
	return H * (H - 1) // 2 + (H * (top - H + 1) + k * (k - 1) + off)

if n >= (H - 1) * H // 2:
	n -= (H - 1) * H // 2
	ans = H - 1
	ans += (n + H - 1) // H
	# ans2 = cb1();

	l = H
	r = 10**18

	while(l < r):
		mid = (l + r) // 2
		# print(l, mid, r)
		# print(f(mid, H))
		if f(mid, H) < cn:
			l = mid + 1
		else:
			r = mid
	ans2 = l
	# print(ans)
	# print(ans2)
	print(min(ans, ans2))

else:
	# print (math.floor(math.sqrt(2 * n) + 0.50000001))
	# exit(0)
	l = 1
	r = H

	while(l < r):
		mid = (l + r) // 2
		if mid * (mid + 1) // 2 < n:
			l = mid + 1
		else:
			r = mid

	print(l)