s = input()

if (len(s) >= 5 and
any(str(i) in s for i in range(10)) and
any(chr(i) in s for i in range(ord('a'), ord('z') + 1)) and
any(chr(i) in s for i in range(ord('A'), ord('Z') + 1))):
    print("Correct")
else:
    print("Too weak")