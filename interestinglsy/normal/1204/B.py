n,l,r = map(int,input().split())
mx = 0
t = 1
for i in range(r):
	mx += t
	t <<= 1
mx += (t>>1)*(n-r)
mi = 0
t = 1
for i in range(l):
	mi += t
	t <<= 1
mi += n-l
print(mi,mx)