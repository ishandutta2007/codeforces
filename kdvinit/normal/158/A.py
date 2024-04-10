#Codeforces - Next Round

n, k = map(int, input().split())
l = list(map(int, input().split()))

ans=0
for x in l:
  if (x>=l[k-1]) and x>0: 
    ans+=1

print(ans)