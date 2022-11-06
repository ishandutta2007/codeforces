n = int(raw_input())
if -129 < n < 128: print "byte"
elif -32769 < n < 32768: print "short"
elif -2147483649 < n < 2147483648: print "int"
elif -9223372036854775809 < n < 9223372036854775808: print "long"
else: print "BigInteger"