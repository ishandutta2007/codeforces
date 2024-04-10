res = 0
cur = 0
sign = +1
for c in input() + "+":
    if c in "+-":
        res += sign * cur
        cur = 0
    if c == '+':
        sign = +1
    if c == '-':
        sign = -1
    cur = cur * 10 + ord(c) - ord('0')
print(res)