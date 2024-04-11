x = input()
n = len(x)

for i in range(n):
  for j in range(i+1,n+1):
    if(x[:i]+x[j:]=="CODEFORCES"):
        print("YES")
        exit(0)
print("NO")
exit(0)