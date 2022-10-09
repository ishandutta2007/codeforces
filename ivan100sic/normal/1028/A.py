n,m=map(int,input().split())
p,q,c=0,0,0
for i in range(n):
	v=input()
	for j in range(m):
		if v[j]=='B':
			p+=i;q+=j;c+=1
print(p//c+1, q//c+1)