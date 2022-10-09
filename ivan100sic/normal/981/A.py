s=input()
n=len(s)
k=0
for i in range(n):
	for j in range(i+1,n+1):
		t=s[i:j]
		if t!=t[::-1]:
			k=max(k,j-i)
print(k)