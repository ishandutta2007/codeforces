a, b = [int(i) for i in raw_input().split()]

maxdigit = max([ord(i) for i in str(a)] + [ord(i) for i in str(b)])
maxdigit = int(chr(maxdigit))

osn = maxdigit + 1

sm = int(str(a), osn) + int(str(b), osn)



cnt = 1
while osn ** cnt <= sm:
    cnt += 1
print cnt