n = int(input())
ans = n // 3 * 2
if n % 3 != 0:
   ans+=1
print(ans)