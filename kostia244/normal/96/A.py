s = input()
ans = False
while len(s) > 6:
  ans |= (s[:7] == "0"*7)
  ans |= (s[:7] == "1"*7)
  s = s[1:]
if ans:
  print("YES")
else:
  print("NO")