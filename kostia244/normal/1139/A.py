a = input()
s = input()
ans = 0
k = 1
for i in s:
  if int(i)%2 == 0:
    ans += k
  k += 1
print(ans)