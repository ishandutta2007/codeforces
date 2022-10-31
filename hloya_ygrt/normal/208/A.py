s = input()
n = len(s)
i = int(0)
t = ""
back = ' '
while i < n:
    if i < n-2 and s[i] == "W" and s[i+1] == "U" and s[i+2] == "B":
     if back != ' ' and i != n-3:
         back = ' '
         t = t + ' '
     i = i + 3
    else:
        back = s[i]
        t = t + s[i]
        i = i + 1

print(t)