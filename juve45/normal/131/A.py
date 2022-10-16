s = input().split()
ans = ""
for x in s:
    if x == x.upper():
        ans += x.lower()
    elif x[1:] == x[1:].upper():
        ans += x.title()
    else:
        ans += x
    ans += ' '
print(ans)