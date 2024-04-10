n = int(input())

ans=0
for i in range (1, n+1):
  cur = input().count('1')
  if (cur>1): ans+=1
print(ans)