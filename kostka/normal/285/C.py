n = int(input())
X = list(map(int, input().split(" ")))
X.sort()
print(sum([abs(X[i-1]-i) for i in range(1,n+1)]))