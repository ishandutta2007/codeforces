[n,l] = list(map(int, input().split(" ")))
X = list(map(int, input().split(" ")))

X = sorted(X)
roz = 2*max(X[0]-0, l-X[-1])
for i in range(1,len(X)):
   roz = max(roz, X[i]-X[i-1])
print(roz/2)