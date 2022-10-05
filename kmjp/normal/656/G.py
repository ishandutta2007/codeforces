F,I,T=map(int,raw_input().split(" "))
L=[0]*10#kitten
ret=0
for f in range(F):
	S=raw_input()
	for x in range(I):
		if S[x]=='Y':
			L[x]+=1
			if L[x]==T:
				ret+=1
print ret