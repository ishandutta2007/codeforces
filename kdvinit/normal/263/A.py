#Codeforces - Beautiful Matrix

ans=0
for i in range(1, 6):
  l = list(map(int, input().split()))
  for j in range (1, 6):
    if(l[j-1]==1):
      ans = abs(i-3) + abs(j-3)

print(ans)