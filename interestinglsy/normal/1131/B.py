import sys
try:
	sys.stdin = open('in.in','r')
	sys.stdout = open('out.out','w')
except: pass

n = int(input())
ca,cb = 0,0
ans = 1
reverse = 0
for ti in range(n):
	va,vb = map(int,input().split())
	# print(ca,cb)
	# print(va,vb)
	# print(ans)
	if reverse:
		va,vb = vb,va
	if va == ca and vb == cb: continue
	if va == ca:
		if cb < ca and vb >= ca:
			ans += 1
		cb = vb
		continue
	if vb == cb:
		if ca < cb and va >= cb:
			ans += 1
		ca = va
		continue
	if ca > cb:
		ca,cb = cb,ca
		va,vb = vb,va
		reverse ^= 1
	if va < cb:
		ca = va
		cb = vb
		continue
	if ca != cb:
		ca = cb
		ans += 1
	minlim = min(va,vb)
	ans += minlim - ca
	ca = va
	cb = vb

print(ans)