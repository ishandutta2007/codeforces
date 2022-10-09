input()
a=list(map(int,input().split()))
n=len(a)
u=n
for i in range(n):
	j=i
	k=0
	while a[j]>0:
		k+=1
		t=j
		j=a[j]-1
		a[t]=0
	if k>0:
		u+=1-k%2
s='Petr'
if u%2>0:
	s='Um_nik'
print(s)