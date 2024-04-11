string = raw_input()
flag = True
for i in string[1:]:
    if ord('a') <= ord(i) <= ord('z'):
        flag = False
if flag:
    new_string = ""
    for i in string:
        if ord('a') <= ord(i) <= ord('z'):
            new_string += chr(ord(i) - ord('a') + ord('A'))
        else:
            new_string += chr(ord(i) - ord('A') + ord('a'))
    print new_string
else:
    print string