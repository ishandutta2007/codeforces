str1 = raw_input()
str2 = raw_input()

Z = ord('Z')
n = len(str1)
i = 0
while i < n:
    x = ord(str1[i])
    y = ord(str2[i])

    if x <= Z: x += 32
    if y <= Z: y += 32

    if x > y: print 1
    if x < y: print -1
    if x != y: break
    i += 1

if i == n: print 0