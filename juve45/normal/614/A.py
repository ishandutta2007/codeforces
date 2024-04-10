l, r, k = map(int, raw_input().split())

p = 1
cnt = 0
for i in range(67):
	if l <= p <= r:
		cnt+=1
		print p, 
	p = p * k

if cnt == 0:
	print -1